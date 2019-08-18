#pragma once
using namespace SccService;
using namespace SccToolchain;

public ref class WebService {
public:
	static SccServiceHelper^ SCCWebService;
	static SccService::Scc::WebServiceResponse^ SCCReturn;
	static SccToolchain::HeartbeatClient^ SccHeartbeat;
};
