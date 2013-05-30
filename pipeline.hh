#ifndef PIPELINE_HH_
# define PIPELINE_HH_

namespace
{
    //
    // Extends the behavior of std::result_of for pipelines of function,
    // setting field type to the type returned by the last function of
    // the pipeline.
    //
    template <typename In, typename F, typename ...Args>
    struct result_of : public result_of<typename std::result_of<F(In)>::type, Args...> {};

    template <typename In, typename F>
    struct result_of<In, F>
    {
        typedef typename std::result_of<F(In)>::type type;
    };
}


//
// Pipeline of function
// usage : pipeline(T arg, f1, f2, ..., fn) with:
// f1: T -> T1
// f2: T1 -> T2
// ...
// fn: Tn -> Tm
// returns the result of fn(...f2(f1(arg)))
//
template <typename In>
In pipeline(In&& a)
{
    return std::forward<In>(a);
}

template <
    typename In,
    typename Function>
auto pipeline(In&& a, Function f) -> decltype (f(std::forward<In>(a)))
{
    return f(std::forward<In>(a));
}

template <
    typename In,
    typename Function,
    typename ...Args>
auto pipeline(In&& a, Function f, Args... args) -> typename result_of<In, Function, Args...>::type
{
    return pipeline<decltype (f(std::forward<In>(a)))>(f(std::forward<In>(a)), args...);
}

#endif /* !PIPELINE_HH_ */
