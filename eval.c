#include "eval.h"


#define TE_FUN(...) ((double(*)(__VA_ARGS__))n->function)
#define M(e) te_eval(n->parameters[e])


double te_eval(const te_expr *n) {
    if (!n) return NAN;

    switch(TYPE_MASK(n->type)) {
        case TE_CONSTANT: return n->value;
        case TE_VARIABLE: return *n->bound;

        case TE_FUNCTION0: case TE_FUNCTION1: case TE_FUNCTION2: case TE_FUNCTION3:
        case TE_FUNCTION4: case TE_FUNCTION5: case TE_FUNCTION6: case TE_FUNCTION7:
            switch(ARITY(n->type)) {
                case 0: return TE_FUN(void)();
                case 1: return TE_FUN(double)(M(0));
                case 2: return TE_FUN(double, double)(M(0), M(1));
                case 3: return TE_FUN(double, double, double)(M(0), M(1), M(2));
                case 4: return TE_FUN(double, double, double, double)(M(0), M(1), M(2), M(3));
                case 5: return TE_FUN(double, double, double, double, double)(M(0), M(1), M(2), M(3), M(4));
                case 6: return TE_FUN(double, double, double, double, double, double)(M(0), M(1), M(2), M(3), M(4), M(5));
                case 7: return TE_FUN(double, double, double, double, double, double, double)(M(0), M(1), M(2), M(3), M(4), M(5), M(6));
                default: return NAN;
            }

        case TE_CLOSURE0: case TE_CLOSURE1: case TE_CLOSURE2: case TE_CLOSURE3:
        case TE_CLOSURE4: case TE_CLOSURE5: case TE_CLOSURE6: case TE_CLOSURE7:
            switch(ARITY(n->type)) {
                case 0: return TE_FUN(void*)(n->parameters[0]);
                case 1: return TE_FUN(void*, double)(n->parameters[1], M(0));
                case 2: return TE_FUN(void*, double, double)(n->parameters[2], M(0), M(1));
                case 3: return TE_FUN(void*, double, double, double)(n->parameters[3], M(0), M(1), M(2));
                case 4: return TE_FUN(void*, double, double, double, double)(n->parameters[4], M(0), M(1), M(2), M(3));
                case 5: return TE_FUN(void*, double, double, double, double, double)(n->parameters[5], M(0), M(1), M(2), M(3), M(4));
                case 6: return TE_FUN(void*, double, double, double, double, double, double)(n->parameters[6], M(0), M(1), M(2), M(3), M(4), M(5));
                case 7: return TE_FUN(void*, double, double, double, double, double, double, double)(n->parameters[7], M(0), M(1), M(2), M(3), M(4), M(5), M(6));
                default: return NAN;
            }

        default: return NAN;
    }

}

#undef TE_FUN
#undef M
