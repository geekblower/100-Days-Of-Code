#include <bits/stdc++.h>
 
void changeCase(string &str) {
    for(int i=0; i<str.length(); i++) {
		if(str[i] >= 'a' && str[i] <= 'z') {
			str[i] = 'A' + (str[i] - 'a');
		} else {
            str[i] = 'a' + (str[i] - 'A');
	    }
	}
}
