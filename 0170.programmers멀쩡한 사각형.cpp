//mentoring 170. 2022.3.5
//유클리드 호제법

using namespace std;

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b,a%b);
}
long long solution(int w,int h) {
    long long total=(long long)w*(long long)h;
    long long x=w+h-gcd(w,h);

    long long answer=total-x;
    return answer;
}
