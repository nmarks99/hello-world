local Shape = {}

function Shape:new(obj)
    self.__index = self
    return setmetatable(obj or {}, self)
end

function Shape:set_origin(x, y)
    self.x, self.y = x, y
end

function Shape:get_origin()
    return self.x, self.y
end


local s = Shape:new{}
s:set_origin(10, 20)
print(s:get_origin())

