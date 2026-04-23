⍝ Set index origin so that ⍳ starts from 0
⎕IO ← 0

⍝ Print first 9 natural numbers
⍝ ⍳ 9
⍝ 0 1 2 3 4 5 6 7 8

⍝ Reshape 9 numbers into 3x3 matrix
⍝ 3 3 ρ ⍳ 9
⍝ 0 1 2
⍝ 3 4 5
⍝ 6 7 8

⍝ Seem to have created a mask
⍝ (3 3 ρ ⍳ 9) ∈ 1 2 3 4 7
⍝ 0 1 1
⍝ 1 1 0
⍝ 0 1 0

⍝ Assigning to a variable r, I guess
r ← (3 3 ρ ⍳ 9) ∈ 1 2 3 4 7

⍝ Pad r towards right and bottom to make it a 5x7 matrix
⍝ 5 7 ↑ r
⍝ 0 1 1 0 0 0 0
⍝ 1 1 0 0 0 0 0
⍝ 0 1 0 0 0 0 0
⍝ 0 0 0 0 0 0 0
⍝ 0 0 0 0 0 0 0

⍝ 'rotate by a vertical axis with ⌽'
⍝ Looks like shifted the whole matrix towards the right by 2 columns. No, that's not it..
⍝ ¯2 ⌽ 5 7 ↑ r
⍝ 0 0 0 1 1 0 0
⍝ 0 0 1 1 0 0 0
⍝ 0 0 0 1 0 0 0
⍝ 0 0 0 0 0 0 0
⍝ 0 0 0 0 0 0 0

⍝⍝⍝ 2 ⌽ 5 7 ↑ r
⍝⍝⍝ 0 0 0 1 1 0 0
⍝⍝⍝ 0 0 1 1 0 0 0
⍝⍝⍝ 0 0 0 1 0 0 0
⍝⍝⍝ 0 0 0 0 0 0 0
⍝⍝⍝ 0 0 0 0 0 0 0
⍝⍝⍝ 1 0 0 0 0 0 1
⍝⍝⍝ 0 0 0 0 0 1 1
⍝⍝⍝ 0 0 0 0 0 0 1
⍝⍝⍝ 0 0 0 0 0 0 0
⍝⍝⍝ 0 0 0 0 0 0 0


⍝ 'Rotate around horizontal axis'
R ← ¯1 ⊖ ¯2 ⌽ 5 7 ↑ r

⍝ R R R

⎕ ← data ← (1 2 3 4) (2 5 8 6) (8 6 2 3) (8 7 6 1)

⍝⍝ Load a library function
⍝⍝ )copy dfns disp




)OFF
