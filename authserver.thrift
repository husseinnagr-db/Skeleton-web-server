include "webserver.thrift"
namespace cpp thrift.authserver

service AuthService {
  // Check if the following user is authorized to access this table
  bool authCheck(
    1: string userkey,
    2: string database,
    3: list<string> tables) throws (1: webserver.MyException ex);
}

