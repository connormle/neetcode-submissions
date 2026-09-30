class Solution {
public:

    string encode(vector<string>& strs) {
        string encodedString{};
        for (const auto& str: strs) {
            encodedString += to_string(str.size()) + "|" + str;
        }
        return encodedString;
    }

    int countDigits(int num) {
        if (num == 0) return 1;
        return floor(log10(abs(num))) + 1;
    }

    vector<string> decode(string s) {
        int index{0};
        vector<string> result{};

        while (index < s.size()) {
            if (index == (s.size() - 1)) return result;
            string slength{};
            int delimiterIndex{};

            for (int i{index}; i < s.size(); ++i) {
                if (s[i] == '|') {
                    delimiterIndex = i;
                    break;
                }
                slength += s[i];
            }

            int length{std::stoi(slength)};
            string copiedString{s.substr(delimiterIndex + 1, length)};
            result.push_back(copiedString);

            index += (length + 1 + countDigits(length));

        }

        return result;
    }
};

