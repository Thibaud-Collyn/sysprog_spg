#include "DecisionOutput.h"

DecisionOutput::DecisionOutput(const spg_addr_t start, const spg_addr_t end) : Module(start, end)
{
    // TODO
}

uint8_t DecisionOutput::read1(const spg_addr_t &address) {
    return 0;
}

spg_register_t DecisionOutput::read2_be(const spg_addr_t &address) {
    return 0;
}

void DecisionOutput::write2_be(const spg_addr_t &address, spg_register_t val) {
}

void DecisionOutput::write1(const spg_addr_t &address, uint8_t val) {
}

CarBrainDecision DecisionOutput::popDecision()
{
    //TODO
    return CarBrainDecision::DECISION_FORWARD;
}

bool DecisionOutput::isDecisionAvailable() {
    //TODO
    return false;
}
