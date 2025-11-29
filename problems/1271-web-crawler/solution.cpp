/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *   public:
 *     vector<string> getUrls(string url);
 * };
 */

class Solution {
public:
    // Extract hostname between "http://" and next '/'
    string getHost(const string &url) {
        int start = 7; // length of "http://"
        int slash = url.find('/', start);
        if (slash == string::npos) 
            return url.substr(start);
        return url.substr(start, slash - start);
    }

    void dfs(const string &url, 
             HtmlParser &parser, 
             const string &host, 
             unordered_set<string> &visited)
    {
        // Already seen?
        if (!visited.insert(url).second)
            return;

        // Explore neighbors
        for (const string &next : parser.getUrls(url)) {
            if (getHost(next) == host) {
                dfs(next, parser, host, visited);
            }
        }
    }

    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        unordered_set<string> visited;
        string host = getHost(startUrl);

        dfs(startUrl, htmlParser, host, visited);

        return vector<string>(visited.begin(), visited.end());
    }
};
