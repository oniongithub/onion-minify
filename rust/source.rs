fn minify_lua(code: &str) -> String {
    let stripped_code = code.replace(char::is_whitespace, " ");
    let minified_code = stripped_code.replace(r"\s*([\(\)\{\}\[\],;])\s*", "$1");
    let minified_code = minified_code.replace(r";(\s*\})", "$1");
    minified_code
}

fn unminify_lua(code: &str) -> String {
    let formatted_code = code.replace(";", ";\n");
    let formatted_code = formatted_code.replace(r"([^\w])function", "$1\nfunction");
    let formatted_code = formatted_code.replace(r"end([^\w])", "end\n$1");
    let formatted_code = formatted_code.replace(r"([=%+\-*/%])", " $1 ");
    formatted_code
}