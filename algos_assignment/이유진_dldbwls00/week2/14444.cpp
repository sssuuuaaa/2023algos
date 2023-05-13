#include <iostream>
using namespace std;

string str;
string astr;
int palindrom[200010];

void manacher() {

    //maxlen 은 위치+펠린드롬의 길이가 가장 긴 값 cur은 그때의 위치 인덱스
    int maxlen = 0, cur = 0;
    int len = astr.size();

    for (int i = 0; i < len; i++) {
        if (i <= maxlen) //현재 위치가 maxlen에 들어있는 펠린드롬 내부에 포함된 경우
            palindrom[i] = min(palindrom[2 * cur - i], maxlen - i);
            /* palindrom[2 * cur - i]: i와 대칭적 위치에 있는 palin의 값이 현재 maxlen의 펠린드롬을 초과하지 않는 경우
               maxlen - i: 초과하는 경우 -> maxlen이 포함된 펠린드롬의 2*cur-i ~ i 까지의 펠린드롬 길이*/
        else 
            palindrom[i] = 0;

        int left = i - palindrom[i] - 1;
        int right = i + palindrom[i] + 1;
        while (left >= 0 && right < len && astr[left] == astr[right]) {
            palindrom[i]++;
            left = i - palindrom[i] - 1;
            right = i + palindrom[i] + 1;
        }

        if (maxlen < i + palindrom[i]) {
            maxlen = i + palindrom[i];
            cur = i;
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> str;

    //짝수 펠린드롬을 위해 문자열 양측에 # 추가 <??
    for (int i = 0; i < str.size(); i++) {
        astr += "#";
        astr += str[i];
    }
    astr += "#";

    manacher();

    int ans = 0;
    for (int i = 0; i < astr.size(); i++) {
        ans = max(ans, palindrom[i]);
        //팰린드롬 중 현재 가장 오른쪽 끝에 위치한 부분을 저장
    }
    cout << ans;

    return 0;
}
