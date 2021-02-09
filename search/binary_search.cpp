template <typename F>
ll my_binary_search(ll ok, ll ng, F is_ok){
    if (ok - ng == 1) return ok;
    ll mid = (ok+ng)/2;
    if (is_ok(mid)) return my_binary_search(mid, ng, is_ok);
    return my_binary_search(ok, mid, is_ok);
}