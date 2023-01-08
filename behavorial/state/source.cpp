#include <iostream>
#include <typeinfo>

class Context;

class State {
public:
    virtual ~State() {}

    void set_context(Context *context) {
        context_ = context;
    }

    virtual void Handle1() = 0;
    virtual void Handle2() = 0;
protected:
    Context *context_;

};

class Context {
 public:
    Context(State *state) : state_(nullptr) {
        TransitionTo(state);
    }
    ~Context() {
        delete state_;
    }

    void TransitionTo(State *state) {
        std::cout << "Context: Transition to " << typeid(*state).name() << ".\n";
        if (state_ != nullptr)
        delete this->state_;
        state_ = state;
        state_->set_context(this);
    }

    void Request1() {
        state_->Handle1();
    }

    void Request2() {
        state_->Handle2();
    }
  
private:
    State *state_;

};

class ConcreteStateA : public State {
public:
    void Handle1() override;

    void Handle2() override {
        std::cout << "ConcreteStateA handles request2.\n";
    }
};

class ConcreteStateB : public State {
public:
    void Handle1() override {
        std::cout << "ConcreteStateB handles request1.\n";
    }
    void Handle2() override {
        std::cout << "ConcreteStateB handles request2.\n";
        std::cout << "ConcreteStateB wants to change the state of the context.\n";
        context_->TransitionTo(new ConcreteStateA);
    }
};

void ConcreteStateA::Handle1() {
    std::cout << "ConcreteStateA handles request1.\n";
    std::cout << "ConcreteStateA wants to change the state of the context.\n";

    this->context_->TransitionTo(new ConcreteStateB);
}

void ClientCode() {
  Context *context = new Context(new ConcreteStateA);
  context->Request1();
  context->Request2();
  delete context;
}

int main() {
    ClientCode();
    return 0;
}