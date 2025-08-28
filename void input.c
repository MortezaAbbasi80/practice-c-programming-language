#include <stdio.h>

// تابعی که انتظار هیچ ورودی ندارد
void secret(void) {
    printf("Secret code executed!\n");
}

int main() {
    // فراخوانی تابع با یک پارامتر جعلی (مثلاً آدرس تابع دیگر)
    secret( (void*)0xdeadbeef ); // کامپایلر ممکن است هشدار دهد، ولی اجرا شود!
    return 0;
}
