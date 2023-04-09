#include <regex>
#include <string>

std::string minify_lua(const std::string& code) {
    std::regex ws_re("\\s+");
    std::string stripped_code = std::regex_replace(code, ws_re, " ");
    std::regex chars_re("\\s*([\\(\\)\\{\\}\\[\\],;])\\s*");
    std::string minified_code = std::regex_replace(stripped_code, chars_re, "$1");
    std::regex semicolon_re(";(\\s*\\})");
    minified_code = std::regex_replace(minified_code, semicolon_re, "$1");
    return minified_code;
}

std::string unminify_lua(const std::string& code) {
    std::regex semicolon_re(";");
    std::string formatted_code = std::regex_replace(code, semicolon_re, ";\n");
    std::regex function_re("([^\\w])function");
    formatted_code = std::regex_replace(formatted_code, function_re, "$1\nfunction");
    std::regex end_re("end([^\\w])");
    formatted_code = std::regex_replace(formatted_code, end_re, "end\n$1");
    std::regex chars_re("([=%+\\-*/%])");
    formatted_code = std::regex_replace(formatted_code, chars_re, " $1 ");
    return formatted_code;
}