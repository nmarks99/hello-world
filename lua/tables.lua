local t = {}

for i=1,10 do
    table.insert(t, {i,i+1})
end

for _,tab in ipairs(t) do
    for i,v in ipairs(tab) do
        print(i,v)
    end
end
