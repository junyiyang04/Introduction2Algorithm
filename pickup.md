Sure, here's an example of how traditional `enum` can lead to name clashes:

```cpp
// First enum
enum Color { Red, Green, Blue };

// Second enum
enum TrafficLight { Red, Yellow, Green };
```

In this example, the compiler will throw an error because `Red` and `Green` are defined in both `Color` and `TrafficLight`. This is a name clash.

However, if we use `enum class`, we can avoid this issue:

```cpp
// First enum class
enum class Color { Red, Green, Blue };

// Second enum class
enum class TrafficLight { Red, Yellow, Green };
```

Now, there's no issue because `Color::Red` and `TrafficLight::Red` are considered distinct and there's no name clash. This is one of the advantages of using `enum class` over traditional `enum`.