-- Returns true if two numbers are within the specified tolerance of each other
function almost_equal(a, b, tol)
    tol = tol or 1e-6
    if (math.abs(a - b) <= tol) then
        return true
    else
        return false
    end
end

function table.almost_equal(t1, t2, tol)
    tol = tol or 1e-6
    assert(#t1 == #t2, "Tables must be the same length")

    for i, _ in ipairs(t1) do
        if not almost_equal(t1[i], t2[i], tol) then
            return false
        end
    end
    return true
end

-- Test
a = 1.0
b = 2.0
almost_equal(a,b)

a = 1.0000001
b = 1.0000002
assert(almost_equal(a,b) == true)

a = 1.001
b = 1.002
assert(almost_equal(a,b) == false)

t1 = {1.123, 2.123, 3.123000002}
t2 = {1.123, 2.123, 3.123000001}
assert(table.almost_equal(t1,t2) == true)

t1 = {1.123, 2.123, 3.1233}
t2 = {1.123, 2.123, 3.1231}
assert(table.almost_equal(t1,t2) == false)
