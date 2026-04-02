class Solution {
public:
    char match(char c) {
        switch (c) {
            case '{':
                return '}';
            case '(':
                return ')';
            case '[':
                return ']';
        }

        return c;
    }

    bool isValid(string s) {
        std::vector<char> stack;
        for (auto c : s) {
            if (c == '(' || c == '{' || c == '[')
                stack.push_back(c);
            else {
                if (stack.size() == 0)
                    return false;
                if (match(stack.back()) != c)
                    return false;
                stack.pop_back();
            }
        }

        return stack.size() == 0;
    }
};
