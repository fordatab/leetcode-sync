#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        // parse into (time, type, payload)
        vector<tuple<int, string, string>> parsed_events;
        parsed_events.reserve(events.size());
        for (const auto &e : events) {
            // e[0] = type, e[1] = time, e[2] = payload (single token in given format)
            parsed_events.emplace_back(stoi(e[1]), e[0], e[2]);
        }

        auto rank = [](const string &s) -> int {
            if (s == "OFFLINE") return 0;
            if (s == "MESSAGE") return 1;
            return 2; // other types (if any)
        };

        sort(parsed_events.begin(), parsed_events.end(),
             [&](const auto &a, const auto &b) {
                 if (get<0>(a) != get<0>(b)) return get<0>(a) < get<0>(b);
                 int ra = rank(get<1>(a));
                 int rb = rank(get<1>(b));
                 if (ra != rb) return ra < rb;
                 // fallback for stability / deterministic order
                 return get<1>(a) < get<1>(b);
             });

        vector<int> mentions(numberOfUsers, 0);
        vector<long long> offline_until(numberOfUsers, 0LL);

        for (const auto &ev : parsed_events) {
            int current_time = get<0>(ev);
            const string &type = get<1>(ev);
            const string &payload = get<2>(ev);

            if (type == "OFFLINE") {
                // payload should be a user id; be defensive and extract digits
                int pos = 0;
                while (pos < (int)payload.size() && !isdigit((unsigned char)payload[pos])) ++pos;
                if (pos == (int)payload.size()) continue; // no id found
                int user_id = stoi(payload.substr(pos));
                if (user_id >= 0 && user_id < numberOfUsers) {
                    offline_until[user_id] = (long long)current_time + 60;
                }
            } else if (type == "MESSAGE") {
                if (payload == "ALL") {
                    for (int i = 0; i < numberOfUsers; ++i) mentions[i]++;
                } else if (payload == "HERE") {
                    for (int i = 0; i < numberOfUsers; ++i) {
                        if (current_time >= offline_until[i]) mentions[i]++;
                    }
                } else {
                    // payload is a mention or space-separated mentions — parse tokens
                    istringstream iss(payload);
                    string token;
                    while (iss >> token) {
                        int pos = 0;
                        while (pos < (int)token.size() && !isdigit((unsigned char)token[pos])) ++pos;
                        if (pos == (int)token.size()) continue;
                        int user_id = stoi(token.substr(pos));
                        if (user_id >= 0 && user_id < numberOfUsers) mentions[user_id]++;
                    }
                }
            }
        }

        return mentions;
    }
};
