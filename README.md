# C++로 알고리즘 공부하자

## input 직접 입력하지 말자!
```
// freopen을 통해 input 미리 설정해놓고 vscode 실행하면 쉽게 자동으로 테스트케이스를 확인 가능하다!
#include <iostream>

using namespaces std;

int main(){
  freopen("input.txt", "r", stdin);
}
```

## 알고리즘 할 때 VSCODE 코드 스니펫 사용하기! (Mac Os)
1. Code -> Preferences -> User Snippets
2. C++ 언어를 쓰는 경우에만 쓰는 snippet을 설정하고 싶었으므로, cpp.json파일을 선택하여 편집.
```
"algo" : {
		"prefix" : "algo",
		"body" : [
			"#include <iostream>",
			"",
			"using namespace std;",
			"",
			"int main(){",
			"  freopen(\"input.txt\", \"r\", stdin);",
			"$0",
			"  return 0;",
			"}",
		]
	}
```
-> c++ 파일에서 "algo"를 쳤을 때 자동으로 "body"안의 내용이 자동 완성되게끔 하는 설정
, "$0"은 자동 완성 이후의 커서의 위치이다.
