/**
 * Autogenerated by Thrift Compiler (0.19.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef WebService_H
#define WebService_H

#include <thrift/TDispatchProcessor.h>
#include <thrift/async/TConcurrentClientSyncInfo.h>
#include <memory>
#include "webserver_types.h"

namespace thrift { namespace webserver {

#ifdef _MSC_VER
  #pragma warning( push )
  #pragma warning (disable : 4250 ) //inheriting methods via dominance 
#endif

class WebServiceIf {
 public:
  virtual ~WebServiceIf() {}
  virtual void read(ReadResult& _return, const ApiKey& apikey, const std::string& userkey, const std::string& query) = 0;
  virtual void write(const ApiKey& apikey, const std::string& userkey, const std::string& data) = 0;
};

class WebServiceIfFactory {
 public:
  typedef WebServiceIf Handler;

  virtual ~WebServiceIfFactory() {}

  virtual WebServiceIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(WebServiceIf* /* handler */) = 0;
  };

class WebServiceIfSingletonFactory : virtual public WebServiceIfFactory {
 public:
  WebServiceIfSingletonFactory(const ::std::shared_ptr<WebServiceIf>& iface) : iface_(iface) {}
  virtual ~WebServiceIfSingletonFactory() {}

  virtual WebServiceIf* getHandler(const ::apache::thrift::TConnectionInfo&) override {
    return iface_.get();
  }
  virtual void releaseHandler(WebServiceIf* /* handler */) override {}

 protected:
  ::std::shared_ptr<WebServiceIf> iface_;
};

class WebServiceNull : virtual public WebServiceIf {
 public:
  virtual ~WebServiceNull() {}
  void read(ReadResult& /* _return */, const ApiKey& /* apikey */, const std::string& /* userkey */, const std::string& /* query */) override {
    return;
  }
  void write(const ApiKey& /* apikey */, const std::string& /* userkey */, const std::string& /* data */) override {
    return;
  }
};

typedef struct _WebService_read_args__isset {
  _WebService_read_args__isset() : apikey(false), userkey(false), query(false) {}
  bool apikey :1;
  bool userkey :1;
  bool query :1;
} _WebService_read_args__isset;

class WebService_read_args {
 public:

  WebService_read_args(const WebService_read_args&);
  WebService_read_args& operator=(const WebService_read_args&);
  WebService_read_args() noexcept
                       : userkey(),
                         query() {
  }

  virtual ~WebService_read_args() noexcept;
  ApiKey apikey;
  std::string userkey;
  std::string query;

  _WebService_read_args__isset __isset;

  void __set_apikey(const ApiKey& val);

  void __set_userkey(const std::string& val);

  void __set_query(const std::string& val);

  bool operator == (const WebService_read_args & rhs) const
  {
    if (!(apikey == rhs.apikey))
      return false;
    if (!(userkey == rhs.userkey))
      return false;
    if (!(query == rhs.query))
      return false;
    return true;
  }
  bool operator != (const WebService_read_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const WebService_read_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class WebService_read_pargs {
 public:


  virtual ~WebService_read_pargs() noexcept;
  const ApiKey* apikey;
  const std::string* userkey;
  const std::string* query;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _WebService_read_result__isset {
  _WebService_read_result__isset() : success(false), ex(false) {}
  bool success :1;
  bool ex :1;
} _WebService_read_result__isset;

class WebService_read_result {
 public:

  WebService_read_result(const WebService_read_result&);
  WebService_read_result& operator=(const WebService_read_result&);
  WebService_read_result() noexcept {
  }

  virtual ~WebService_read_result() noexcept;
  ReadResult success;
  MyException ex;

  _WebService_read_result__isset __isset;

  void __set_success(const ReadResult& val);

  void __set_ex(const MyException& val);

  bool operator == (const WebService_read_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(ex == rhs.ex))
      return false;
    return true;
  }
  bool operator != (const WebService_read_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const WebService_read_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _WebService_read_presult__isset {
  _WebService_read_presult__isset() : success(false), ex(false) {}
  bool success :1;
  bool ex :1;
} _WebService_read_presult__isset;

class WebService_read_presult {
 public:


  virtual ~WebService_read_presult() noexcept;
  ReadResult* success;
  MyException ex;

  _WebService_read_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _WebService_write_args__isset {
  _WebService_write_args__isset() : apikey(false), userkey(false), data(false) {}
  bool apikey :1;
  bool userkey :1;
  bool data :1;
} _WebService_write_args__isset;

class WebService_write_args {
 public:

  WebService_write_args(const WebService_write_args&);
  WebService_write_args& operator=(const WebService_write_args&);
  WebService_write_args() noexcept
                        : userkey(),
                          data() {
  }

  virtual ~WebService_write_args() noexcept;
  ApiKey apikey;
  std::string userkey;
  std::string data;

  _WebService_write_args__isset __isset;

  void __set_apikey(const ApiKey& val);

  void __set_userkey(const std::string& val);

  void __set_data(const std::string& val);

  bool operator == (const WebService_write_args & rhs) const
  {
    if (!(apikey == rhs.apikey))
      return false;
    if (!(userkey == rhs.userkey))
      return false;
    if (!(data == rhs.data))
      return false;
    return true;
  }
  bool operator != (const WebService_write_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const WebService_write_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class WebService_write_pargs {
 public:


  virtual ~WebService_write_pargs() noexcept;
  const ApiKey* apikey;
  const std::string* userkey;
  const std::string* data;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _WebService_write_result__isset {
  _WebService_write_result__isset() : ex(false) {}
  bool ex :1;
} _WebService_write_result__isset;

class WebService_write_result {
 public:

  WebService_write_result(const WebService_write_result&);
  WebService_write_result& operator=(const WebService_write_result&);
  WebService_write_result() noexcept {
  }

  virtual ~WebService_write_result() noexcept;
  MyException ex;

  _WebService_write_result__isset __isset;

  void __set_ex(const MyException& val);

  bool operator == (const WebService_write_result & rhs) const
  {
    if (!(ex == rhs.ex))
      return false;
    return true;
  }
  bool operator != (const WebService_write_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const WebService_write_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _WebService_write_presult__isset {
  _WebService_write_presult__isset() : ex(false) {}
  bool ex :1;
} _WebService_write_presult__isset;

class WebService_write_presult {
 public:


  virtual ~WebService_write_presult() noexcept;
  MyException ex;

  _WebService_write_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class WebServiceClient : virtual public WebServiceIf {
 public:
  WebServiceClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  WebServiceClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void read(ReadResult& _return, const ApiKey& apikey, const std::string& userkey, const std::string& query) override;
  void send_read(const ApiKey& apikey, const std::string& userkey, const std::string& query);
  void recv_read(ReadResult& _return);
  void write(const ApiKey& apikey, const std::string& userkey, const std::string& data) override;
  void send_write(const ApiKey& apikey, const std::string& userkey, const std::string& data);
  void recv_write();
 protected:
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class WebServiceProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  ::std::shared_ptr<WebServiceIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext) override;
 private:
  typedef  void (WebServiceProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_read(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_write(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  WebServiceProcessor(::std::shared_ptr<WebServiceIf> iface) :
    iface_(iface) {
    processMap_["read"] = &WebServiceProcessor::process_read;
    processMap_["write"] = &WebServiceProcessor::process_write;
  }

  virtual ~WebServiceProcessor() {}
};

class WebServiceProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  WebServiceProcessorFactory(const ::std::shared_ptr< WebServiceIfFactory >& handlerFactory) noexcept :
      handlerFactory_(handlerFactory) {}

  ::std::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo) override;

 protected:
  ::std::shared_ptr< WebServiceIfFactory > handlerFactory_;
};

class WebServiceMultiface : virtual public WebServiceIf {
 public:
  WebServiceMultiface(std::vector<std::shared_ptr<WebServiceIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~WebServiceMultiface() {}
 protected:
  std::vector<std::shared_ptr<WebServiceIf> > ifaces_;
  WebServiceMultiface() {}
  void add(::std::shared_ptr<WebServiceIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  void read(ReadResult& _return, const ApiKey& apikey, const std::string& userkey, const std::string& query) override {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->read(_return, apikey, userkey, query);
    }
    ifaces_[i]->read(_return, apikey, userkey, query);
    return;
  }

  void write(const ApiKey& apikey, const std::string& userkey, const std::string& data) override {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->write(apikey, userkey, data);
    }
    ifaces_[i]->write(apikey, userkey, data);
  }

};

// The 'concurrent' client is a thread safe client that correctly handles
// out of order responses.  It is slower than the regular client, so should
// only be used when you need to share a connection among multiple threads
class WebServiceConcurrentClient : virtual public WebServiceIf {
 public:
  WebServiceConcurrentClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot, std::shared_ptr< ::apache::thrift::async::TConcurrentClientSyncInfo> sync) : sync_(sync)
{
    setProtocol(prot);
  }
  WebServiceConcurrentClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot, std::shared_ptr< ::apache::thrift::async::TConcurrentClientSyncInfo> sync) : sync_(sync)
{
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void read(ReadResult& _return, const ApiKey& apikey, const std::string& userkey, const std::string& query) override;
  int32_t send_read(const ApiKey& apikey, const std::string& userkey, const std::string& query);
  void recv_read(ReadResult& _return, const int32_t seqid);
  void write(const ApiKey& apikey, const std::string& userkey, const std::string& data) override;
  int32_t send_write(const ApiKey& apikey, const std::string& userkey, const std::string& data);
  void recv_write(const int32_t seqid);
 protected:
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
  std::shared_ptr< ::apache::thrift::async::TConcurrentClientSyncInfo> sync_;
};

#ifdef _MSC_VER
  #pragma warning( pop )
#endif

}} // namespace

#endif
