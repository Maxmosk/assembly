unit sort;

interface

procedure SORT (var arr: PQWord; size: QWord);

implementation

procedure SORT (var arr: PQWord; size: QWord);
var
    swap_buffer, i: QWord;
    flag: boolean;
begin
    repeat
        flag := true;

        for i := 0 to size - 1 do
        begin
            if arr[i] > arr[i + 1] then
            begin
                swap_buffer := arr[i];
                arr[i] := arr[i + 1];
                arr[i + 1] := swap_buffer;
                flag := false;
            end;
        end;
    until flag;
end;

end.

