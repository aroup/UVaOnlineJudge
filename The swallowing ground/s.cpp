#include <cstdio>
#include <iostream>
using namespace std;

int main() {
	int testcase, number, up, down;

	scanf("%d", &testcase);
	while (testcase--) {
		scanf("%d", &number);

		bool y = true;
		scanf("%d %d", &up, &down);
		int diff = up - down;

		for (int i = 0; i < number - 1; i++) {
			scanf("%d %d", &up, &down);
			if (diff != up - down)
				y = false;
		}

		if (y)
			printf("yes\n");
		else
			printf("no\n");

		if (testcase)
			printf("\n");
	}

	return 0;
}
