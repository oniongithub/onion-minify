function minifyLua(code)
    local strippedCode = string.gsub(code, "%s+", " ")
    local minifiedCode = string.gsub(strippedCode, "%s*([%(%){}%[%],;])%s*", "%1")
    minifiedCode = string.gsub(minifiedCode, ";(%s*})", "%1")
    return minifiedCode
end

function unminifyLua(code)
    local formattedCode = string.gsub(code, ";", ";\n")
    formattedCode = string.gsub(formattedCode, "([^%w])function", "%1\nfunction")
    formattedCode = string.gsub(formattedCode, "end([^%w])", "end\n%1")
    formattedCode = string.gsub(formattedCode, "([=%+%-%*/%%])", " %1 ")
    return formattedCode
end