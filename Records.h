#ifndef _RECORDS_H_
#define _RECORDS_H_
#include <map>
#include <string>
#include "ObserverPattern.h"

using std::map;
using std::string;

struct Record
{
  int wins = 0;
  int losses = 0;
};

class Records : public Observable
{
  private:
    map <const string, Record> _player_records;

  protected:
    Records();

  public:
    static Records& instance();
    void update_record(string player_name, bool won);
    void show_records();
    map <const string, Record> get_records();

};

#endif
