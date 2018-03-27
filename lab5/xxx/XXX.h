//
// Created by semcjaku on 27.03.18.
//

#ifndef JIMP_EXERCISES_XXX_H
#define JIMP_EXERCISES_XXX_H


class XXX {
public:
    XXX();
    ~XXX();

    XXX(const XXX& xxx);
    XXX & operator=(const XXX& xxx);

    XXX(XXX &&xxx);
    XXX & operator=(XXX &&xxx);

private:
    char *name_;
};




#endif //JIMP_EXERCISES_XXX_H
