#include "consumer/StreamingConsumerImpl.h"

using namespace io::openmessaging;
using namespace io::openmessaging::consumer;

StreamingConsumerImpl::StreamingConsumerImpl(jobject proxy) : ServiceLifecycleImpl(proxy) {
    CurrentEnv ctx;
    const char *klassStreamingConsumer = "io/openmessaging/consumer/StreamingConsumer";
    classStreamingConsumer = ctx.findClass(klassStreamingConsumer);
}

StreamingConsumerImpl::~StreamingConsumerImpl() {
    CurrentEnv ctx;
    ctx.deleteRef(classStreamingConsumer);
}

NS::shared_ptr<KeyValue> StreamingConsumerImpl::properties() {
    throw OMSException("Not Implemented");
}

std::vector<std::string> StreamingConsumerImpl::streams() {
    throw OMSException("Not Implemented");
}

std::vector<std::string> StreamingConsumerImpl::consumers() {
    throw OMSException("Not Implemented");
}

NS::shared_ptr<MessageIterator> StreamingConsumerImpl::current() {
    throw OMSException("Not Implemented");
}

NS::shared_ptr<MessageIterator> StreamingConsumerImpl::begin() {
    throw OMSException("Not Implemented");
}

NS::shared_ptr<MessageIterator> StreamingConsumerImpl::end() {
    throw OMSException("Not Implemented");
}

NS::shared_ptr<MessageIterator> StreamingConsumerImpl::seekByTime(long timestamp) {
    throw OMSException("Not Implemented");
}
