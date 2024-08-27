 #include<bits/stdc++.h>

using namespace std;

int main() {
    char b_levels[] = {'.',',','-','~',':',';','=','!','*','#','$','@'};
    // समय 
    for(int t = 0; t <= 20; t++) {
        system("clear"); // पिछला गोला साफ करने के लिए 
        // रोशनी की दिशा  
        double lx_cap = 10.0*cos(2.0*M_PI*t/20)/sqrt(10*10+25*25);
        double ly_cap = 10.0*sin(2.0*M_PI*t/20)/sqrt(10*10+25*25);
        // ऊपर से नीचे तक जाना 
        for(int y = 20; y >= -20; y--) {
            // रेखा की शुरुवात और अंत निकालना 
            int x1 = -round(sqrt(20*20-y*y));
            int x2 = round(sqrt(20*20-y*y));
            int x = -20;
            while(x < x1) {cout << ' '; x++;} // ख़ाली हिस्सा शुरू छोड़ना 
            // अंत तक गोले को भरना 
            while(x <= x2) {
                int tp = max(20*20 - y*y - x*x, 0);  // नकारात्मक का वर्गमूल (स्क्वायर रुत) नही होता
                double b = max(lx_cap*x/20 + ly_cap*y/20 + 25.0*sqrt(tp)/(20*sqrt(10*10+25*25)), 0.0);  // चमक
                char b_character = b_levels[(int)(b*11)]; // चमक से मिलता अक्षर
                cout << b_character;
                x++;
            }
            cout << endl;
        }
        this_thread::sleep_for(chrono::milliseconds(600));
    }
    return 0;
}
