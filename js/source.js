function minifyLua(code) {
    let strippedCode = code.replace(/\s+/g, " ");
    let minifiedCode = strippedCode.replace(/\s*([\(\)\{\}\[\],;])\s*/g, "$1");
    minifiedCode = minifiedCode.replace(/;(\s*\})/g, "$1");
    return minifiedCode;
}

function unminifyLua(code) {
    let formattedCode = code.replace(/;/g, ";\n");
    formattedCode = formattedCode.replace(/([^\w])function/g, "$1\nfunction");
    formattedCode = formattedCode.replace(/end([^\w])/g, "end\n$1");
    formattedCode = formattedCode.replace(/([=%+\-*/%])/g, " $1 ");
    return formattedCode;
}