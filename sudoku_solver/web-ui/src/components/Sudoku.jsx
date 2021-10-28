import { React, useState, useEffect } from 'react';

function Sudoku() {
    
  const [gridSize, setGridSize] = useState();
  
  const handleSubmit = () => {
    console.log(gridSize);
  }
  
  return (
        <div className="App">
          <header className="App-header">
            <input placeholder="size of sudoku" onChange={gridSize => {setGridSize(gridSize);console.log(gridSize);}}/>
            <button style={{padding: "20px"}} onClick={handleSubmit()}></button>
          </header>
        </div>
      );
}

export default Sudoku;