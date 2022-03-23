#include <bandit/bandit.h>
#include <snowhouse/snowhouse.h>

using namespace bandit;
using namespace snowhouse;

go_bandit([](){
    describe("Example tests", [](){
        it("test passes", [&](){ AssertThat(69, Equals(69)); });
        it("test fails", [&](){ AssertThat(69, Equals(420)); });
    });
});
