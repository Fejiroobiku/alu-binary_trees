# compile.ps1 - Compile all tasks with main files

# Get all main.c files
$mainFiles = Get-ChildItem *main.c

foreach ($mainFile in $mainFiles) {
    # Extract task number
    $taskNumber = $mainFile.Name -replace '-main.c', ''
    
    # Find the corresponding implementation file
    $implFile = Get-ChildItem "$taskNumber-binary_tree_*.c"
    
    if ($implFile) {
        $outputName = "$taskNumber-task.exe"
        
        Write-Host "Compiling Task $taskNumber..." -ForegroundColor Yellow
        Write-Host "Files: $($implFile.Name) $($mainFile.Name)" -ForegroundColor Cyan
        
        # Try compiling with just these files first
        gcc -Wall -Wextra -Werror -pedantic $implFile.Name $mainFile.Name -o $outputName
        
        if ($LASTEXITCODE -eq 0) {
            Write-Host "✓ Success: $outputName" -ForegroundColor Green
        } else {
            Write-Host "✗ Failed. Trying with Task 0 included..." -ForegroundColor Yellow
            
            # Try including Task 0 if it exists
            $task0File = Get-ChildItem "0-binary_tree_node.c"
            if ($task0File) {
                gcc -Wall -Wextra -Werror -pedantic $task0File.Name $implFile.Name $mainFile.Name -o $outputName
                
                if ($LASTEXITCODE -eq 0) {
                    Write-Host "✓ Success with Task 0: $outputName" -ForegroundColor Green
                } else {
                    Write-Host "✗ Still failed" -ForegroundColor Red
                }
            }
        }
    }
}

Write-Host "`nDone! Run any task with: .\N-task.exe" -ForegroundColor Green