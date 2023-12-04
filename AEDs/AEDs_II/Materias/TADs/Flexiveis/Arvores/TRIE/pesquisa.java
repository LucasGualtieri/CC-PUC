boolean Pesquisar(String s) {
    int len = 0;
    No i = this.raiz;
    
    while (i != null && len < s.length()) {
        char c = s.charAt(len++);
        i = i.alfabeto[hash(c)];
    }
    
    return len == s.length() && i.isFolha;
}