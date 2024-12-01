# Библиотека *gfx.blockwraps*

Библиотека для работы с *обертками блоков*.

Обёртки блоков введены для реализации анимации разрушения блоков и могут
использоваться для иных задач.

```lua
-- Создаёт обертку на указанной позиции, с указанной текстурой.
-- Возвращает id обёртки.
gfx.blockwraps.wrap(position: vec3, texture: str) --> int

-- Удаляет обертку, если она существует.
gfx.blockwraps.unwrap(id: int)

-- Меняет позицию обёртки, если она существует.
gfx.blockwraps.set_pos(id: int, position: vec3)

-- Меняет текстуру обёртки, если она существует.
gfx.blockwraps.set_texture(id: int, texture: str)
```

Обертки не удаляются автоматически без вызова `unwrap`.