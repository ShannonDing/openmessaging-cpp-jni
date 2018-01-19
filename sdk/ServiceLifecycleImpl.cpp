#include "ServiceLifecycleImpl.h"

BEGIN_NAMESPACE_2(io, openmessaging)

    ServiceLifecycleImpl::ServiceLifecycleImpl(jobject proxy)  : _proxy(proxy) {
        CurrentEnv current;
        jclass classServiceLifecycleLocal = current.env->FindClass("io/openmessaging/ServiceLifecycle");
        classServiceLifecycle = reinterpret_cast<jclass>(current.env->NewGlobalRef(classServiceLifecycleLocal));
        current.env->DeleteLocalRef(classServiceLifecycleLocal);

        midStartup = getMethod(current, classServiceLifecycle, "startup", "()V");
        midShutdown = getMethod(current, classServiceLifecycle, "shutdown", "()V");
    }

    ServiceLifecycleImpl::~ServiceLifecycleImpl() {
        CurrentEnv current;
        current.env->DeleteGlobalRef(_proxy);
        current.env->DeleteGlobalRef(classServiceLifecycle);
    };

    void ServiceLifecycleImpl::startup() {
        CurrentEnv current;
        current.env->CallVoidMethod(_proxy, midStartup);
    }

    void ServiceLifecycleImpl::shutdown() {
        CurrentEnv current;
        current.env->CallVoidMethod(_proxy, midShutdown);
    }

END_NAMESPACE_2(io, openmessaging)