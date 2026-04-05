#include <bits/stdc++.h>
#include "bird.h"

using namespace std;

void bird_does_Something(Bird*& bird){
    bird->eat();
    bird->fly();
    bird->eat();
    bird->eat();
    bird->fly();
    bird->eat();
    bird->eat();
    bird->fly();
    bird->eat();
    bird->eat();
    bird->fly();
    bird->eat();
}

int main(){
    Bird* bird1 = new sparrow();
    bird_does_Something(bird1);

    Bird* bird2 = new eagle();
    bird_does_Something(bird2);

    Bird* bird3 = new pigeon();
    bird_does_Something(bird3);
    return 0;
}

// Note :- kisi bhi abstract class ka ya cpp kae interface ka object nahi ban sakta 
// means hum Bird* bird = new bird(); easa nahi kar sakte bird ka object nahi ban sakta because vo abstract class hai.