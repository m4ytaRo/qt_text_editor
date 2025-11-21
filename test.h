#ifndef TEST_H
#define TEST_H
#include "Question.h"
#include <QList>

class Test
{
public:
    Test();

private:
    QList <Question*> QuestionList;
};

#endif // TEST_H
