#ifndef QUESTION_H
#define QUESTION_H

class Question
{
public:
    Question();
    virtual bool validateAnswer () const = 0;
};

#endif // QUESTION_H
