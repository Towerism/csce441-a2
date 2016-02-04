class Entity {
public:
  Entity(int x, int y) : x(x), y(y) { }

  virtual void update() = 0;
  virtual void draw() = 0;

  virtual void keyboardEvent(char key, int x, int y) = 0;
  virtual void mouseEvent(int button, int state, int x, int y) = 0;

  virtual ~Entity() = default;

protected:
  int x, y;
};
