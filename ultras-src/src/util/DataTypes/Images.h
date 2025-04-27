#ifndef IMAGES_H
#define IMAGES_H

#include<stdio.h>
#include<string>

using namespace std;

class Images {
    public:
    	Images();
    	string getImage(int index);
        string getRandomImage();
        string images[5];
};

#endif