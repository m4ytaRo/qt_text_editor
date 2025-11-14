#ifndef SINGLECHOICEQUESTION_H
#define SINGLECHOICEQUESTION_H
#include "question.h"
#include <QStringList>



class SingleChoiceQuestion : public Question
{
public:
    SingleChoiceQuestion();
    bool validateAnswer() const;
private:
    QStringList options;
};

#endif // SINGLECHOICEQUESTION_H
