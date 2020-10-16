#ifndef AUTHORQUERYCONDITION_H
#define AUTHORQUERYCONDITION_H


class AuthorQueryCondition
{
private:
    int limit;
    int offsetId;
public:
    AuthorQueryCondition(int limit = 10, int offsetId = 0);
    ~AuthorQueryCondition();
    int getLimit();
    void setLimit(int limit);
    int getOffsetId();
    void setOffsetId(int offsetId);
};

#endif // AUTHORQUERYCONDITION_H
