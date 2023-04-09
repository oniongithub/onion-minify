public class LuaMinifier {
    public static String minifyLua(String code) {
        String strippedCode = code.replaceAll("\\s+", " ");
        String minifiedCode = strippedCode.replaceAll("\\s*([\\(\\)\\{\\}\\[\\],;])\\s*", "$1");
        minifiedCode = minifiedCode.replaceAll(";(\\s*\\})", "$1");
        return minifiedCode;
    }

    public static String unminifyLua(String code) {
        String formattedCode = code.replaceAll(";", ";\n");
        formattedCode = formattedCode.replaceAll("([^\\w])function", "$1\nfunction");
        formattedCode = formattedCode.replaceAll("end([^\\w])", "end\n$1");
        formattedCode = formattedCode.replaceAll("([=%+\\-*/%])", " $1 ");
        return formattedCode;
    }
}