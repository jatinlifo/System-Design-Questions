/* URL Shortner System Design

The need for efficient and concise URL management has become important in today’s
 digital world. URL shortening services help convert long and complex links into short
, easy-to-share URLs. This improves usability, especially on social media and messaging platforms.

// Short URLs are simple to share and remember.
// Helps track clicks and manage links effectively.
// Example: A long e-commerce product link can be shortened into something like bit.ly/xyz123, 
making it easier to share on platforms like WhatsApp or Twitter.


*/

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;


// class URL {
// public:

//     string originalUrl;
//     string shortUrl;

//     URL(string originalUrl, string shortUrl) {

//         this->originalUrl = originalUrl;
//         this->shortUrl = shortUrl;
//     }
// };

// this is my generator service take all responsibilty to generate urls
class ShortUrlGenerator {
public:
    virtual string generate() = 0;

    virtual ~ShortUrlGenerator() {}
};

// firts strategy

class CounterGenerator : public ShortUrlGenerator {
private:
    int id = 1;
public:

    string generate() override {
        return "abc" + to_string(id++);
    }
};

// second strategy and further future ma new method add kiya ja sakta hai

class RandomGenerator : public ShortUrlGenerator {
private:
    int id = 1;

public:

    string generate() override {

        return "xyz123";
    }
};

class URLDatbases {
public:

    virtual void save(string shortUrl, string oriignalUrl) = 0;
    virtual string find(string shortUrl) = 0;

    ~URLDatbases() {}

};

class SaveMySql : public URLDatbases {

private:
    
    unordered_map<string, string> mySql;

public:

    void save(string shortUrl, string originalUrl) override {

         if (shortUrl.empty() || originalUrl.empty()) {
            cout << "Both filled are required" << endl;
            return;
        }

        mySql[shortUrl] = originalUrl;

        cout << "Saved in mySQL" << endl;
    }

    string find(string shortUrl) override {

        if (!mySql.count(shortUrl)) {
            return "URL Not Found in MYSql";
        }

        return mySql[shortUrl];
    }
};

class SaveMongoDB : public URLDatbases {

private:
    unordered_map<string, string> mongoDB;

public:

    void save(string shortUrl, string originalUrl) override {

        if (shortUrl.empty() || originalUrl.empty()) {
            cout << "Both filled are required" << endl;
            return;
        }
        mongoDB[shortUrl] = originalUrl;

        cout << "Saved in MongoDB" << endl;
    }

    string find(string shortUrl) {

        if (!mongoDB.count(shortUrl)) {
            return "URl Not found in mongoDB";
        }

        return mongoDB[shortUrl];
    }
};

// main service

class URLShortenerService {
private:

    ShortUrlGenerator* generator;
    URLDatbases* database;

public:

    URLShortenerService(ShortUrlGenerator* generator, URLDatbases* database) {
        this->generator = generator;
        this->database = database;
    }

    string shorten(string originalUrl) {

        string shortUrl = generator->generate();

        database->save(shortUrl, originalUrl);

        return shortUrl;
    }

    string resolve(string shortUrl) {

        return database->find(shortUrl);
    }
};

int main () {

    // counter method
    CounterGenerator counterGenerator;
    SaveMySql saveMySql;
    URLShortenerService service1(&counterGenerator, &saveMySql);

    string shortUrl1 = service1.shorten("http://google.com/api/v1");

    cout << "ShortURL generate using service 1 : Counter Generator" << "  -> " << shortUrl1 << endl;
    cout << "Resolve generate original URl " << "  -> " << service1.resolve(shortUrl1) << endl;

    // random method

    RandomGenerator randomGenerator;
    SaveMongoDB saveMongoDb;
    URLShortenerService service2(&randomGenerator, &saveMongoDb);

    string shortUrl2 = service2.shorten("http://micorsoft.com/api/v1/blog");

    cout << "ShortURL generate using service 2 : Random Generator" << " -> " << shortUrl2 << endl;
    cout << "Resolve generate original URL" << "  -> " << service2.resolve(shortUrl2);
}