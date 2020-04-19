#include <stdio.h>
#include "calculate.h"

void test(char t[], int re){
    long int cal = calculate(t);
    bool res = cal==re;
    if(res) printf("result : success\n");
    else printf("result : failure\n");    
}

int main(){
    test("(1+2)", (1+2));
    test("(1*2)", (1*2));
    test("(1-2)", (1-2));
    test("(189+245)", (189+245));
    test("((1+2)+2)", (((1+2)+2)));
    test("((1+2)*2)", (((1+2)*2)));
    test("((1-2)*2)", (((1-2)*2)));
    test("((1+2)+(2+3))", ((1+2)+(2+3)));
    test("((1+2)*(2+3))", ((1+2)*(2+3)));
    test("((1*2)+(2*3))", ((1*2)+(2*3)));
    test("((1+2)+((3+3)+3))", ((1+2)+((3+3)+3)));
    test("((1+2)-((3+3)+3))", ((1+2)-((3+3)+3)));
    test("((1872+212)+2221)", ((1872+212)+2221));
    test("(((20+98)+2)-((3+3)+3))", (((20+98)+2)-((3+3)+3)));
    test("((1123+22)*(21231+32332))", ((1123+22)*(21231+32332)));
    test("((((20+98)+2)-((3+3)+3))*2)", ((((20+98)+2)-((3+3)+3))*2));
    test("((((20+98)+2)-((3+3)+3))*(1-1000))", ((((20+98)+2)-((3+3)+3))*(1-1000)));
}