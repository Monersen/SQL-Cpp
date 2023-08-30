#include <iostream>
#include <Wt/Dbo/Dbo.h>
#include <Wt/Dbo/backend/Postgres.h>
#include <string>
using namespace std;

class Book;
class Sale;
class Stock;
class Shop;

class Publisher {
public:
    string name = "";

    Wt::Dbo::collection<Wt::Dbo::ptr<Book>> books;

    template<typename Action>
    void persist(Action& a)
    {
        Wt::Dbo::field(a, name, "name");
        Wt::Dbo::hasMany(a, books, Wt::Dbo::ManyToOne, "publisher");

    }
};

class Book {
public:
    string title = "";
    Wt::Dbo::ptr<Publisher> publisher;
    Wt::Dbo::collection<Wt::Dbo::ptr<Stock>> stocks;

    template<typename Action>
    void persist(Action& a)
    {
        Wt::Dbo::field(a, title, "title");
        Wt::Dbo::belongsTo(a, publisher, "publisher");
        Wt::Dbo::hasMany(a, stocks, Wt::Dbo::ManyToOne, "book");
    }
};

class Shop {
public:
    string name = "";
    Wt::Dbo::collection<Wt::Dbo::ptr<Stock>> stocks;


    template<typename Action>
    void persist(Action& a)
    {
        Wt::Dbo::field(a, name, "name");
        Wt::Dbo::hasMany(a, stocks, Wt::Dbo::ManyToOne, "shop");
    }
};

class Stock {
public:
    int count;
    Wt::Dbo::ptr<Book> book;
    Wt::Dbo::ptr<Shop> shop;
    Wt::Dbo::collection<Wt::Dbo::ptr<Sale>> sales;

    template<typename Action>
    void persist(Action& a)
    {
        Wt::Dbo::field(a, count, "count");
        Wt::Dbo::belongsTo(a, book, "book");
        Wt::Dbo::belongsTo(a, shop, "shop");
        Wt::Dbo::hasMany(a, sales, Wt::Dbo::ManyToOne, "stock");
    }
};

class Sale {
public:
    string date;
    int price;
    int count;
    Wt::Dbo::ptr<Stock> stock;


    template<typename Action>
    void persist(Action& a)
    {
        Wt::Dbo::field(a, date, "date");
        Wt::Dbo::field(a, price, "price");
        Wt::Dbo::field(a, count, "count");
        Wt::Dbo::belongsTo(a, stock, "stock");

    }
};

void enter_new_data_to_the_created_db(Wt::Dbo::Session& session) {

    Wt::Dbo::Transaction transaction(session);

    //Новые данные в таблицу Publisher
    unique_ptr<Publisher> p1 = make_unique<Publisher>();
    p1->name = "Rabbit run";
    auto ptr_pub1 = session.add(move(p1));

    unique_ptr<Publisher> p2 = make_unique<Publisher>();
    p2->name = "99 Francs";
    auto ptr_pub2 = session.add(move(p2));

    //Новые данные в таблицу Book
    unique_ptr<Book> b1 = make_unique<Book>();
    b1->title = "Alice in wonderland";
    b1->publisher = ptr_pub1;
    auto ptr_book1 = session.add(move(b1));

    unique_ptr<Book> b2 = make_unique<Book>();
    b2->title = "Brave new world";
    b2->publisher = ptr_pub1;
    auto ptr_book2 = session.add(move(b2));

    unique_ptr<Book> b3 = make_unique<Book>();
    b3->title = "The Buried Giant";
    b3->publisher = ptr_pub1;
    auto ptr_book3 = session.add(move(b3));

    unique_ptr<Book> b4 = make_unique<Book>();
    b4->title = "Fight Club";
    b4->publisher = ptr_pub2;
    auto ptr_book4 = session.add(move(b4));

    unique_ptr<Book> b5 = make_unique<Book>();
    b5->title = "Bible";
    b5->publisher = ptr_pub2;
    auto ptr_book5 = session.add(move(b5));

    unique_ptr<Book> b6 = make_unique<Book>();
    b6->title = "The suicide club";
    b6->publisher = ptr_pub2;
    auto ptr_book6 = session.add(move(b6));

    //Новые данные в таблицу Shop
    unique_ptr<Shop> s1 = make_unique<Shop>();
    s1->name = "Metaphysics of moral";
    auto ptr_shop1 = session.add(move(s1));

    unique_ptr<Shop> s2 = make_unique<Shop>();
    s2->name = "Thus Spake Zarathustra";
    auto ptr_shop2 = session.add(move(s2));

    unique_ptr<Shop> s3 = make_unique<Shop>();
    s3->name = "City of Jade";
    auto ptr_shop3 = session.add(move(s3));

    //Новые данные в таблицу Stock
    unique_ptr<Stock> t1 = make_unique<Stock>();
    t1->book = ptr_book1;
    t1->shop = ptr_shop1;
    t1->count = 400;
    auto ptr_stock1 = session.add(move(t1));

    unique_ptr<Stock> t2 = make_unique<Stock>();
    t2->book = ptr_book2;
    t2->shop = ptr_shop1;
    t2->count = 200;
    auto ptr_stock2 = session.add(move(t2));

    unique_ptr<Stock> t3 = make_unique<Stock>();
    t3->book = ptr_book3;
    t3->shop = ptr_shop1;
    t3->count = 300;
    auto ptr_stock3 = session.add(move(t3));

    unique_ptr<Stock> t4 = make_unique<Stock>();
    t4->book = ptr_book4;
    t4->shop = ptr_shop2;
    t4->count = 180;
    auto ptr_stock4 = session.add(move(t4));

    unique_ptr<Stock> t5 = make_unique<Stock>();
    t5->book = ptr_book5;
    t5->shop = ptr_shop2;
    t5->count = 250;
    auto ptr_stock5 = session.add(move(t5));

    unique_ptr<Stock> t6 = make_unique<Stock>();
    t6->book = ptr_book6;
    t6->shop = ptr_shop3;
    t6->count = 500;
    auto ptr_stock6 = session.add(move(t6));

    //Новые данные в таблицу Sale
    unique_ptr<Sale> l1 = make_unique<Sale>();
    l1->date = "31-08-2023";
    l1->price = 500;
    l1->count = 50;
    l1->stock = ptr_stock1;
    session.add(move(l1));

    unique_ptr<Sale> l2 = make_unique<Sale>();
    l2->date = "31-08-2023";
    l2->price = 350;
    l2->count = 60;
    l2->stock = ptr_stock2;
    session.add(move(l2));

    unique_ptr<Sale> l3 = make_unique<Sale>();
    l3->date = "31-08-2023";
    l3->price = 450;
    l3->count = 100;
    l3->stock = ptr_stock3;
    session.add(move(l3));

    unique_ptr<Sale> l4 = make_unique<Sale>();
    l4->date = "31-08-2023";
    l4->price = 550;
    l4->count = 120;
    l4->stock = ptr_stock4;
    session.add(move(l4));

    unique_ptr<Sale> l5 = make_unique<Sale>();
    l5->date = "31-08-2023";
    l5->price = 750;
    l5->count = 90;
    l5->stock = ptr_stock5;
    session.add(move(l5));

    unique_ptr<Sale> l6 = make_unique<Sale>();
    l6->date = "31-08-2023";
    l6->price = 850;
    l6->count = 30;
    l6->stock = ptr_stock6;
    session.add(move(l6));

    transaction.commit();
}
bool is_number(const string& s) {
    for (char c : s) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

int main()
{
    try {
        string pasw;
        cout << "Enter the password to connect to the database: ";
        cin >> pasw;

        string connectionString = "host = localhost "
            "port = 5432 "
            "dbname = Publisher "
            "user = postgres "
            "password = netology";

        auto postgres = make_unique<Wt::Dbo::backend::Postgres>(connectionString);
        Wt::Dbo::Session s;
        s.setConnection(move(postgres));
        s.mapClass<Publisher>("publisher");
        s.mapClass<Book>("book");
        s.mapClass<Shop>("shop");
        s.mapClass<Stock>("stock");
        s.mapClass<Sale>("sale");

        try {
            s.createTables();
            cout << "Table created\n";
        }
        catch (const Wt::Dbo::Exception& e) {
            cout << "Table already exist, exception: " << e.what() << endl;
        }

        string user_ans;
        cout << "Enter the publisher's id number:" << endl;
        cin >> user_ans;
        Wt::Dbo::Transaction t(s);
        if (is_number(user_ans)) {

            int pub_id = s.query<int>("SELECT id FROM publisher").where("id = ?").bind(user_ans);
            if (pub_id == 0) {
                cout << "Unfortunately, there is no such publisher in our database!" << endl;
            }
            else
            {
                string pub_name = s.query<string>("SELECT name FROM publisher").where("id = ?").bind(user_ans);
                Wt::Dbo::collection<Wt::Dbo::ptr<Book>> books = s.find<Book>().where("publisher_id = ?").bind(pub_id);
                cout << "Information that is stored in our database: " << endl;
                cout << "Publisher name: " << pub_name << endl;
                cout << "The publisher has published -> " << books.size() << " books" << endl;
                int book_num = 1;
                for (const Wt::Dbo::ptr<Book>& p : books)
                {
                    cout << book_num << ") " << p->title << endl;
                    book_num++;
                }
                auto result = s.query < string, Wt::Dbo::DirectBinding>("SELECT shop.name "
                    "FROM shop "
                    "JOIN stock ON stock.shop_id = shop.id "
                    "JOIN book ON book.id = stock.id "
                    "JOIN publisher ON publisher.id = book.publisher_id "
                    "WHERE publisher.id =?  GROUP BY shop.name")
                    .bind(user_ans).resultList();

                cout << "The publisher has -> " << result.size() << " shops" << endl;
                int shop_num = 1;
                for (auto it = result.begin(); it != result.end(); ++it)
                {
                    cout << shop_num << ") " << *it << endl;
                    shop_num++;
                }

            }
            t.commit();
        }
        else {
            cout << "Unfortunately, there is no such publisher in our database!" << endl;
        }
    }
    catch (const exception& e) {
        cout << "Connection's problem: " << e.what() << endl;
    }

}