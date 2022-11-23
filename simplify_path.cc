#include <string>
#include <vector>

enum Type {
    NAME,
    DOT,
    DDOT
};

struct Token {
    Type type;
    std::string token;
    Token(Type type, std::string token = std::string()): type(type), token(token) {};
};

struct Parser {
    std::string str;
    size_t pos = 0;

    Parser(std::string input) {
        str = input;
    }
    Token* next() {
        if (pos >= str.size()) {
            return nullptr;
        }
        int dots = 1;
        switch(str[pos]) {
            case '/':
                ++pos;
                while (pos < str.size() && str[pos] == '/')
                    ++pos;
                return next();
            case '.':
                ++pos;
                while (pos < str.size() && str[pos] == '.')
                    ++dots, ++pos;
                if (pos < str.size() && str[pos] != '/') {
                    return new Token(Type::NAME, std::string(dots, '.').append(next()->token));
                }
                switch(dots) {
                    case 1:
                        return new Token(Type::DOT);
                    case 2:
                        return new Token(Type::DDOT);
                    default:
                        return new Token(Type::NAME, std::string(dots, '.'));
                }
            default:
                std::string s = std::string();
                while (pos < str.size() && str[pos] != '/') {
                    s.push_back(str[pos]);
                    ++pos;
                }
                return new Token(Type::NAME, s);
        }
    }
};

class Solution {
public:
    std::string simplifyPath(std::string path) {
        std::vector<std::string> stack;
        Parser p = Parser(path);
        Token* token;
        while ((token = p.next())) {
            switch (token->type) {
                case NAME:
                    stack.push_back(token->token);
                    break;
                case DOT:
                    break;
                case DDOT:
                    if (!stack.empty())
                        stack.pop_back();
            }
        }
        std::string answer = std::string("/");
        if (!stack.size())
            return answer;
        for (size_t i = 0; i < stack.size() - 1; ++i) {
            answer.append(stack[i].append("/"));
        }
        answer.append(stack[stack.size() - 1]);
        return answer;
    }
};

int main(int argc, char* argv[]) {
    if (argc <= 1)
        return 0;
    char* str = argv[1];
    Solution sol;
    std::string simple = sol.simplifyPath(std::string(str));
    printf("%s\n", simple.c_str());
    return 0;
}