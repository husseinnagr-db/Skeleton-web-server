namespace cpp thrift.webserver

struct ApiKey {
  1: required string orgName;
  2: required string keyName;
}

struct ReadResult {
  // 200 for success, 4xx for user error, 5xx for server errors
  1: required i32 returnCode;

  // This is a json representation of the query results
  2: optional string res;
  
  // Used to fetch the remaining results if the query was too large.
  // No cursor implies all results have been returned.
  3: optional string cursor;
}

exception MyException {
    1: i32 errorCode,
    2: string errorMessage
}

service WebService {
    // Read an object by its ID
    ReadResult read(
      1: ApiKey apikey,
      2: string userkey,
      3: string query) throws (1: MyException ex);

    // Write an object
    void write(
      1: ApiKey apikey,
      2: string userkey,
      3: string data) throws (1: MyException ex);
}

