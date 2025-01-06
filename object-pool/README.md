## Factory Method

Object pooling can offer a significant performance boost. It is most effective in situations where
the cost of initializing a class instance is high, the rate of instantiation of a class is high, and
the number of instantiations in use at any one time is low.

### When to use

* applications that create and destroy many objects within a short period, such as game engines
  (e.g., bullets, particles), network servers, or real-time systems.

