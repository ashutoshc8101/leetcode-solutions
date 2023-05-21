class Solution {
public:
    string intToRoman(int num) {
        unordered_map<int, string> ump;

        ump[1] = "I";
        ump[2] = "II";
        ump[3] = "III";
        ump[4] = "IV";
        ump[5] = "V";
        ump[6] = "VI";
        ump[7] = "VII";
        ump[8] = "VIII";
        ump[9] = "IX";
        ump[10] = "X";
        ump[20] = "XX";
        ump[30] = "XXX";
        ump[40] = "XL";
        ump[50] = "L";
        ump[60] = "LX";
        ump[70] = "LXX";
        ump[80] = "LXXX";
        ump[90] = "XC";
        ump[100] = "C";
        ump[200] = "CC";
        ump[300] = "CCC";
        ump[400] = "CD";
        ump[500] = "D";
        ump[600] = "DC";
        ump[700] = "DCC";
        ump[800] = "DCCC";
        ump[900] = "CM";
        ump[1000] = "M";
        ump[2000] = "MM";
        ump[3000] = "MMM";

        string str = to_string(num);

        string result = "";

        for (int i = 0; i < str.size(); i++) {
            result += ump[int(str[i] - '0') * pow(10, str.size() - i - 1)];
        }

        return result;
    }
};