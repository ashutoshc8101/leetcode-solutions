class Solution {
public:
    unordered_map<string, string> mp;
    unordered_map<string, string> reverse_mp;
    long long index = 0;

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string shortUrl = "http://tinyurl.com/" + to_string(index++);
        mp[shortUrl] = longUrl;
        reverse_mp[longUrl] = shortUrl;

        return shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return mp[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));