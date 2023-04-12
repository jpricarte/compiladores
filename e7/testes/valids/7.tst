bool a, b[2], c[3^5];

bool foo() {
    a = foo();
    b[a] = 4;
    c[b[a]^4] = 5;
}