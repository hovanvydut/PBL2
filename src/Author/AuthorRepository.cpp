#include "src/Author/AuthorRepository.h"


AuthorRepository* AuthorRepository::_authorRepository = nullptr;

AuthorRepository::AuthorRepository() {
    this->query = DB::getInstance()->getQuery();
}

AuthorRepository* AuthorRepository::getInstance() {
    if (_authorRepository == nullptr) {
        _authorRepository = new AuthorRepository;
    }
    return _authorRepository;
}

AuthorRepository::~AuthorRepository() {
    // delete this->query;
}

Author AuthorRepository::findFirst() {
    this->query->exec("SELECT author_id, name, created_at, updated_at, deleted_at "
                "FROM authors");

    this->query->first();
    return parse(this->query);
}

Listt<Author>* AuthorRepository::findAll() {
    Listt<Author> *list = new LinkedListt<Author>();

    // default query conditions
    int limit = 7;
    int offsetId = 30;

    this->query->prepare("SELECT TOP(:limit) author_id, name, created_at, updated_at, deleted_at "
                         "FROM authors WHERE author_id > :offsetId");
    this->query->bindValue(":limit", limit);
    this->query->bindValue(":offsetId", offsetId);

    this->query->exec();
    while(this->query->next()) {
        list->add(parse(this->query));
    }

    return list;
}

Listt<Author>* AuthorRepository::findAll(AuthorQueryCondition* conditions) {
    Listt<Author> *list = new LinkedListt<Author>();

    // default query conditions
    int limit = 10;
    int offsetId = 0;

    if (conditions != nullptr) {
        limit = conditions->getLimit() ? conditions->getLimit() : limit;
        offsetId = conditions->getOffsetId() ?  conditions->getOffsetId() : offsetId;
    }

    this->query->prepare("SELECT TOP(:limit) author_id, name, created_at, updated_at, deleted_at "
                         "FROM authors WHERE author_id > :offsetId");
    this->query->bindValue(":limit", limit);
    this->query->bindValue(":offsetId", offsetId);

    this->query->exec();
    while(this->query->next()) {
        list->add(parse(this->query));
    }
    return list;
}

Author AuthorRepository::findById(int author_id) {
    this->query->prepare("SELECT author_id, name, created_at, updated_at, deleted_at "
                        "FROM authors "
                        "WHERE author_id = :author_id");

    this->query->bindValue(":author_id", author_id);
    this->query->exec();
    this->query->first();

    return parse(this->query);
}

int AuthorRepository::count() {
    this->query->exec("SELECT COUNT(author_id) count FROM dbo.authors");
    this->query->next();
    return this->query->value(0).toInt();
}

Author AuthorRepository::parse(QSqlQuery* query) {
    int id = query->value(0).toInt();
    QString name = query->value(1).toString();
    QDate created_at = query->value(2).toDate();
    QDate updated_at = query->value(3).toDate();
    QDate deleted_at = query->value(4).toDate();
    return Author(id, name, created_at, updated_at, deleted_at);
}

